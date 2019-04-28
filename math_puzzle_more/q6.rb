# 長辺の長さが1000以下正方形が20個

s = Time.now
@memo = {}

def g(n, m, k)
  return @memo[[n, m, k]] if @memo[[n, m, k]]
  return @memo[[n, m, k]] = @memo[[m, n, k]] if @memo[[m, n, k]]
  return 0 if n * m < k
  return k == 1 ? 1 : 0 if n == m

  return @memo[[n, m, k]] = g([n - m, m].max, [n - m, m].min, k - 1)
end

def f(n, m)
  ans = 0
  2.upto(n){|a|
    1.upto(a-1){|b|
      ans += g(a, b, m)
    }
  }
  ans
end

puts f(1000, 20)
puts "#{Time.now - s}s"

# f(n, m)
# a / gcd(a, b) = m
# a = m*gcd(a, b)

# f(8, 5)
# a / gcd(a, b) = 5
# a = 5*gcd(a, b)

# a = 5のとき
# 1 = gcd(5, b)
# b = 1, 2, 3, 4
