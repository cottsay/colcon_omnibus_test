use std::ffi::CStr;
use std::os::raw::c_char;

unsafe extern "C" {
    fn underlay_meson_func() -> *const *const c_char;
    fn underlay_meson_free(arr: *const *const c_char);
}

fn str_array_to_vec(mut arr: *const *const c_char) -> Vec<String> {
    let mut res: Vec<String> = Vec::new();

    unsafe {
        while !(*arr).is_null() {
            let cstr = CStr::from_ptr(*arr);
            res.push(cstr.to_string_lossy().to_string());
            arr = arr.wrapping_add(1);
        }
    }

    return res;
}

pub fn overlay_cargo_func() -> Vec<String> {
    let mut res: Vec<String> = Vec::new();

    unsafe {
        let underlay_meson = underlay_meson_func();
        if !underlay_meson.is_null() {
            res.append(&mut str_array_to_vec(underlay_meson));
            underlay_meson_free(underlay_meson);
        }
    }

    res.push("overlay_cargo".to_string());

    return res;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn check_underlay_func() {
        let expected = vec!["underlay_meson".to_string(), "overlay_cargo".to_string()];
        let actual = overlay_cargo_func();

        assert_eq!(expected, actual);
    }
}
