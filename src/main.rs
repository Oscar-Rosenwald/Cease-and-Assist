use anyhow::Result;
use clap::Parser;
use std::path::PathBuf;

use lexing::token::Token;

mod common;
mod lexing;

#[derive(Parser)]
struct Arg {
    #[arg(required = true)]
    target_file: PathBuf,
}

fn main() -> Result<()> {
    let arg = Arg::parse();

    let lexer = lexing::lexer::Lexer::new(arg.target_file)?;
    let tokens = lexer.parse()?;

    Ok(())
}
