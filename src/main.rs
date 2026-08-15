use clap::Parser;

mod command_line;
mod grammar;
mod tokeniser;
mod util;

fn main() -> Result<(), util::CeaseError> {
    let args = command_line::CommandLineArgs::try_parse().map_err(|e| {
        util::CeaseError::author(
            format!("Cannot parse command line arguments: {e}"),
            util::ErrorLocation::Generic,
        )
    })?;

    let tokens = tokeniser::tokeniser::parse_file(&args.file)?;

    for token in tokens {
        println!("{token}");
    }

    Ok(())
}
