// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful


template <typename it>
void swap(it a, it b)
{
    it::value_type tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename it>
it min_elem(it begin, it end)
{
    it smallest;

    if (begin == end)
        return end;
    smallest = begin;
    begin++;

    for (; begin != end; begin++)
    {
        if (*begin < *smallest)
            smallest = begin;
    }

    return smallest;
}

template <typename it>
void my_selection_sort(it begin, it end) 
{
    for (it i = begin; i != end; ++i)
    {
        swap(i, min_elem(i, end));
    }
}