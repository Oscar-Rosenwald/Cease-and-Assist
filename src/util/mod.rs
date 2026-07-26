//! Package util defines the common tools and structs used by the rest of the
//! compiler.

pub mod error;
pub mod location;

pub use error::Error as CeaseError;
pub use error::*;
pub use location::*;
