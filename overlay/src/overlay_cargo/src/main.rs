fn main() {
    let vals = overlay_cargo::overlay_cargo_func();

    for val in vals.iter() {
        println!("{}", val);
    }
}
