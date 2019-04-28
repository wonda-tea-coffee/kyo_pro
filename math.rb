# 自然数a, bの最大公約数を求める
def gcd(a, b)
  return gcd(b, a) if a < b
  return 1 if b == 1
  return b if a % b == 0
  return gcd(b, a % b)
end

# 自然数nの各桁の和を求める
def digits_sum(n)
  ans = 0
  while n > 0
    ans += n % 10
    n /= 10
  end
  ans
end

def rad(n, from, to)
  n.to_s.to_i(from).to_s(to)
end
