use anyhow::{Result, anyhow};
use clap::Parser;
use std::path::PathBuf;

mod ast;
mod common;
mod lexing;
mod parser;

#[derive(Parser)]
struct Arg {
    #[arg(required = true)]
    target_file: PathBuf,
}

fn main() -> Result<()> {
    let arg = Arg::parse();

    let tokens =
        lexing::lexer::parse_file(arg.target_file.as_path()).map_err(|e| anyhow!("{e}"))?;

    let _abstract_syntax_tree = ast::Tree::from_tokens(tokens).map_err(|e| anyhow!("{e}"))?;

    Ok(())
}
