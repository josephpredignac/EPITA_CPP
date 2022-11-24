// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template<typename CONT>
CONT find_min(CONT begin, CONT end, auto cmp)
{
    CONT min = begin;
    begin ++;
    while(begin != end)
    {
        min = cmp(*begin, *min) ? begin : min;
        begin++;
    }

    return min;
}

template<typename CONT>
void swap(CONT a, CONT b)
{
    auto tmp = *a;
    *a = *b;
    *b = tmp;
}

template<typename CONT>
void my_selection_sort(CONT begin, CONT end, auto cmp)
{
    for (CONT i = begin; i != end; ++i) {
        swap(i, find_min(i, end, cmp));
    }
}
