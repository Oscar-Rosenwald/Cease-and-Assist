use std::collections::VecDeque;

/// Presents a window with 3 elements which slides over the `original` vector.
/// For each slice, `filter` is called. If `filter` returns true, the middle
/// element is removed from the returned vector, which is at worst a copy of the
/// `originl` vector.
///
/// The first and last elements cannot be removed using this function. Do it
/// yourself. It's not that hard.
pub fn filter_window<F, T: Clone>(mut original: Vec<T>, filter: F) -> VecDeque<T>
where
    F: Fn(&T, &T, &T) -> bool,
{
    if original.len() < 3 {
        return VecDeque::from(original);
    }

    let mut ret_vec = VecDeque::new();

    let windows = original.windows(3);

    for window in windows {
        let first = window.get(0).unwrap();
        let second = window.get(1).unwrap();
        let third = window.get(2).unwrap();

        let include = filter(first, second, third);
        if include {
            ret_vec.push_back(second.clone());
        }
    }

    ret_vec.push_front(original.remove(0));
    ret_vec.push_back(original.remove(original.len() - 1));

    return ret_vec;
}
