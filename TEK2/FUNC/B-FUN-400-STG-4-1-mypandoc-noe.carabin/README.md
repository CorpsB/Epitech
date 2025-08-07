# mypandoc

> 📝 Un convertisseur de documents minimaliste en Haskell, inspiré de Pandoc.

---

## 🧠 Présentation

**mypandoc** est un convertisseur de documents multi-format développé en **Haskell**, basé sur le célèbre outil [Pandoc](https://pandoc.org/). Il permet de parser un fichier texte structuré (Markdown, XML ou JSON) et de le convertir dans un autre format en respectant une structure interne commune (`Document`).

Ce projet a été réalisé dans le cadre du module **B-FUN-400** à **Epitech**.

---

## 📦 Fonctionnalités

- ✅ Parsing maison (aucune bibliothèque tierce autorisée)
- ✅ Conversion depuis et vers :
  - Markdown
  - XML
  - JSON
- ✅ Détection automatique du format d'entrée via l'extension du fichier
- ✅ Interface en ligne de commande
- ✅ Écriture sur la sortie standard ou dans un fichier
- ❌ Pas de support pour HTML, LaTeX ou d’autres formats avancés (non requis)

---

## 🚀 Build & Run

### Requirements

- [Stack](https://docs.haskellstack.org/en/stable/README/) (>= 2.1.3)
- GHC (>= 9.x)
- make

### Compilation

To compile the project:

```bash
make
```

### Available options

| Option | Description                          |
|--------|--------------------------------------|
| -i     | Path to the input file               |
| -f     | Output format (markdown, xml, json)  |
| -o     | *(Optional)* Path to output file     |
| -e     | *(Optional)* Input format if not inferable |

---

## 🧪 Examples

### 🔁 Markdown to JSON (output to console)

### 🧪 Exemples

#### 🔁 Markdown vers JSON (affichage dans la console)
```bash
./mypandoc -i exemple.md -f json
```

## 🗂 Project structure

.
├── app/
│   └── Main.hs              -- Main entry point  
├── src/
│   ├── Document.hs          -- Internal data types  
│   ├── MarkdownParser.hs    -- Markdown parser  
│   ├── XmlParser.hs         -- XML parser  
│   ├── ParsingJson.hs       -- JSON parser  
│   ├── WritingJson.hs       -- JSON writer  
│   ├── WritingXml.hs        -- XML writer  
│   ├── PrintMarkdown.hs     -- Markdown writer  
│   └── Utils.hs             -- Parsing combinators  
├── test/
│   └── examples/            -- Test files  
├── generate.sh              -- Haddock documentation generator  
├── Makefile  
└── README.md  

---

## 📚 Documentation

```bash
./BONUS/generate.sh
```


HTML files will be generated in the `docs/` folder.  
You can then open `docs/index.html` in your browser.

---

## ⚠️ Error Handling

The program exits with **code 84** in the following cases:

- 📁 Input file not found or empty  
- ❌ Invalid input or output format  
- 🧩 Parsing error  
- 🧨 Malformed command-line arguments 

---

## 🚀 Future Improvements

- ✅ Add automated tests  
- ✅ Support more formats: HTML, LaTeX...  
- ✅ Better error messages  
- 💡 Bonus: Web UI  

---

## 🙌 Authors

Project developed by **Brice Laurent, Thibaut Louis, Raphaël Gall, and Noé Carabin** as part of the `B-FUN-400` module at **Epitech**.

---

## 🌟 License

This project is licensed under the **MIT License**.


