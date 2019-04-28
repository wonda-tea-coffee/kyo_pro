def g(n, m, k)
  return 0 if n * m < k
  return k == 1 ? 1 : 0 if n == m

  return n - m >= m ? g(n - m, m, k - 1) : g(m, n - m, k - 1)
end

def f(n, m)
  ans = 0
  2.upto(n){|a|
    lim_a = a - 1
    1.upto(lim_a){|b|
      ans += g(a, b, m)
    }
  }
  ans
end

puts f(1000, 20)
