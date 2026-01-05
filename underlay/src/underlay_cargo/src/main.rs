fn main() {
    let vals = underlay_cargo::underlay_cargo_func();

    for val in vals.iter() {
        println!("{}", val);
    }
}
