import express from 'express';
import multer from 'multer';
import path from 'path';
import fs from 'fs';
import { execFile } from 'child_process';

const app = express();
const port = 80;

app.use(express.static('public'));

const storage = multer.diskStorage({
  destination: 'uploads/',
  filename: (req, file, cb) => {
    const filename = `${Date.now()}-${file.originalname}`;
    cb(null, filename);
  },
});
const upload = multer({ storage });

app.post('/upload', upload.single('fichier'), (req, res) => {
  if (!req.file) {
    res.status(400).send('Aucun fichier envoyé.');
    return;
  }

  const inputPath = req.file.path;
  const outputExt = 'md'; // pour markdown — à adapter dynamiquement si tu veux plus tard
  const outputPath = path.join('outputs', `${req.file.filename}-out.${outputExt}`);

  const command = './mypandoc';
  const args = ['-i', inputPath, '-f', 'markdown', '-o', outputPath];

  execFile(command, args, (error, stdout, stderr) => {
    if (error) {
      console.error('Erreur mypandoc:', stderr || error.message);
      res.status(500).send('Erreur lors de la conversion du fichier.');
      return;
    }

    res.download(outputPath);
  });
});

app.listen(port, '0.0.0.0', () => {
  console.log(`✅ Serveur lancé sur http://localhost:${port}`);
});
