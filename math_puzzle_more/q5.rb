$moneys = [10000, 5000, 2000, 1000, 500, 100, 50, 10, 5, 1]

def cnt_money(n)
  ans = 0
  $moneys.each do |m|
    ans += n / m
    n %= m
  end
  ans
end

$memo = {}
def comb(n, r)
  return $memo[[n, r]] if $memo[[n, r]]
  return $memo[[n, r]] = 1 if r == 0 || n == r
  return $memo[[n, r]] = $memo[[n, n - r]] if $memo[[n, n - r]]

  $memo[[n, r]] = comb(n - 1, r - 1) + comb(n - 1, r)
end

ans = 0
n = 45
0.upto(n) {|i|
  ans += cnt_money(comb(n, i))
}

puts ans
