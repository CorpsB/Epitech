import express from 'express';
import multer from 'multer';
import path from 'path';
import fs from 'fs';
import { execFile } from 'child_process';

const app   = express();
const port  = 80;
const BIN   = path.resolve('../../mypandoc');
const TMP   = { up: 'uploads', out: 'outputs' };
const FORMATS = ['xml', 'json', 'markdown'];

app.use(express.static('public'));

//  5Mo max ; refuse les doubles extensions cheloues
const storage = multer.diskStorage({
  destination: TMP.up,
  filename: (_, file, cb) => cb(null, Date.now() + '-' + path.basename(file.originalname)),
});
const upload = multer({
  storage,
  limits: { fileSize: 5 * 1024 * 1024 },
  fileFilter: (_, file, cb) => cb(null, /^[a-zA-Z0-9._-]+$/.test(file.originalname)),
});

app.post('/upload', upload.single('fichier'), (req, res) => {
  if (!req.file)            return res.status(400).send('Fichier manquant');
  const outFmt = (req.body.format || '').toLowerCase();
  if (!FORMATS.includes(outFmt))
    return res.status(400).send('Format de sortie interdit');

  const inPath  = req.file.path;
  const outPath = path.join(TMP.out, `${req.file.filename}-out.${outFmt}`);

  const args = ['-i', inPath, '-f', outFmt, '-o', outPath];
  const child = execFile(BIN, args, { timeout: 10_000 }, (err, _stdout, stderr) => {
    if (err) {
      const code = (err as any).code ?? 500;
      console.error('mypandoc error (code', code, '):', stderr || err.message);
      return res.status(500).send(`Échec de conversion (code ${code})`);
    }
    res.download(outPath, err2 => {
      fs.unlink(inPath, () => {});
      fs.unlink(outPath, () => {});
      if (err2) console.error('download error', err2);
    });
  });
});

app.listen(port, '0.0.0.0', () =>
  console.log(`✅ Node écoute sur http://localhost:${port}  nginx proxy 80 → 3000`),
);