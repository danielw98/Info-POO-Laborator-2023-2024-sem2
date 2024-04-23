public class MyGenericClass<T> where T : IComparable<T>
{
    public T Data { get; set; }

    public bool IsGreaterThan(T value)
    {
        return Data.CompareTo(value) > 0;
    }
}