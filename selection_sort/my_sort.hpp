

template <typename it>
void my_selection_sort(it begin, it end) 
{
    for (it i = begin; i != end; ++i)
    {
        it pivot = i;
        for (it j = i; j != end; j++)
            if (*j < *pivot) pivot = j;
        auto tmp = *i;
        *i = *pivot;
        *pivot = tmp;
    }
}
