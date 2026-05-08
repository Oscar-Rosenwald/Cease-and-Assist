use anyhow::{Result, anyhow};
use std::fs::File;
use std::io::{self, BufRead};
use std::path::PathBuf;

pub struct SourceFile {
    path: PathBuf,
    pub(super) content: io::Lines<io::BufReader<File>>,
}

impl SourceFile {
    fn new(path: PathBuf) -> io::Result<Self> {
        let file = File::open(&path)?;
        Ok(Self {
            path,
            content: io::BufReader::new(file).lines(),
        })
    }
}

pub struct Lexer {
    src_file: SourceFile,
}

impl Lexer {
    pub fn new(src_file: PathBuf) -> Result<Self> {
        Ok(Self {
            src_file: SourceFile::new(src_file)?,
        })
    }

    pub fn parse(self) -> Result<()> {
        for (number, line) in self.src_file.content.enumerate() {
            let line = line.map_err(|e| anyhow!("Failed to read line: {e}"))?;
            println!("{number}: {line}");
        }

        Ok(())
    }
}
