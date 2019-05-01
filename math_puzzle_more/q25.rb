@memo = {}

def g(n)
  return @memo[n] if @memo[n]
  return 1 if n <= 1

  ans = 0
  1.upto(n){|i|
    ans += g(i-1)*g(n-i)
  }
  @memo[n] = ans
end

def f(n)
  g((n-1)/2)
end

puts f(39)
