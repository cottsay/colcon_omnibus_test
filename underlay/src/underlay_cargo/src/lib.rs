pub fn underlay_cargo_func() -> Vec<String> {
    vec!["underlay_cargo".to_string()]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn check_underlay_func() {
        let expected = vec!["underlay_cargo".to_string()];
        let actual = underlay_cargo_func();

        assert_eq!(expected, actual);
    }
}
