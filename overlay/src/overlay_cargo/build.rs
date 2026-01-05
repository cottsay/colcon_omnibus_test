extern crate pkg_config;

fn main() {
    pkg_config::Config::new()
        .atleast_version("0.0.1")
        .probe("underlay_meson")
        .unwrap();
    println!("cargo::rerun-if-changed=build.rs");
}
