template<size_t>
struct debug{};

template <class T>
ostream& print_tuple(ostream& out, const T& t, debug<1> ) {
  return out << get<tuple_size<T>::value-1>(t);
}

template <class T, size_t idx>
ostream& print_tuple(ostream& out, const T& t, debug<idx> ) {
  out << get< tuple_size<T>::value-idx >(t) << ',';
  return print_tuple(out, t, debug<idx-1>());
}

template <class... Args>
ostream& operator<<(ostream& out, const tuple<Args...>& t) {
  out << '['; 
  print_tuple(out, t, debug<sizeof...(Args)>()); 
  return out << "]\n";
}
