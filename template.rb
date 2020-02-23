require 'date'

# 2つの日付の差を求める
# Date - DateはRationalになることに注意
def period_days(d1, d2)
  (d1 - d2).abs.to_i
end

def max(a, b)
  a > b ? a : b
end

def min(b)
  a < b ? a : b
end

# n_C_r (mod m)
def combination(n, r, m)
  return 0 if r < 0 || r > n
  return 1 if r == 0 || r == n
  fact2(n, r, m) * inverse(fact(n, m) % m, m) % m
end

# n! (mod m)
#
# キャッシュあり
# O(n)
@fact = [1]
def fact(n, m)
  if n > @fact.size
    f = @fact[-1]
    (@fact.size + 1..n).each do |i|
      f = (f * i) % m
      @fact << f
    end
  end
  @fact[n - 1]
end

# n * (n - 1) * ... * (n - r + 1) (mod m)
def fact2(n, r, m)
  f = 1
  n.downto(n - r + 1) do |i|
    f = (f * i) % m
  end
  f
end

# 逆元
# n^x ≡ 1 (mod m) なるxを求める
#
# mが素数であることを前提としていることに注意する
def inverse(n, m)
  pow(n, m - 2, m)
end

# べき乗(MODあり)(繰り返し２乗法)
def pow(x, n, m)
  ans = 1
  while n > 0
    ans = ans * x % m if n.odd?
    x = x * x % m
    n >>= 1
  end
  ans
end

puts fact2(5, 2, 10**9 + 7)