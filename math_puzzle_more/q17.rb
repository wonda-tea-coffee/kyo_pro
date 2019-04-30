# n人がm台のリフトに乗るパターンは
# リフトがk人乗りだとすると、
# 1, ~ :n-1人がm-1台のリフトに乗るパターン
# 2, ~ :n-2人がm-2台のリフトに乗るパターン
# 3, ~ :n-3人がm-3台のリフトに乗るパターン
# ...
# k, ~ :n-k人がm-k台のリフトに乗るパターン
# 以上の合計で求められる

# 以下特殊ケース
# n人が1台のリフトに乗るパターンは、
# リフトの制限人数以下ならば1, そうでなければ0
#
# n人がn台のリフトに乗るパターンは1

$lim = 6
@memo = {}

# n人がm台リフトに乗るパターンを求める
def solve(n, m)
  return n <= $lim ? 1 : 0 if m == 1
  return 1 if n == m
  return @memo[[n, m]] if @memo[[n, m]]

  ret = 0
  i = 1
  while i < n && i <= $lim
    ret += solve(n-i, m-1)
    i += 1
  end

  @memo[[n, m]] = ret
end

n = 32
ans = 0
1.upto(n){|i| ans += solve(n, i)}

puts ans
