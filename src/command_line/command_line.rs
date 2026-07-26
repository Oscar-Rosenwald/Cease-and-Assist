use clap::Parser;

#[derive(Parser)]
pub struct CommandLineArgs {
    #[arg(required = true, help = "File to build")]
    pub file: std::path::PathBuf,
}
