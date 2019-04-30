@memo = {}

# 両端を考慮しない
def g(n, m)
  return 0 if n < m
  return n <= 1 ? 1 : 0 if m == 0
  return 1 if n == m
  return @memo[[n, m]] if @memo[[n, m]]

  @memo[[n, m]] = g(n - 1, m - 1) + g(n - 2, m - 1)
end

# 両端を使う
def f(n, m)
  g(n - 2, m - 2)
end

puts f(50, 35)
