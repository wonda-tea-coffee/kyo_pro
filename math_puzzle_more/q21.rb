s = Time.now

@memo = {}

# nページの本をm日で読むパターンの総数を求める
# ただし、前日にはkページ読んだものとする
def solve2(n, m, k)
  return @memo[[n, m, k]] if @memo[[n, m, k]]

  return m == 0 ? 1 : 0 if n == 0
  # 残り1日のときは、残りのページ数が前日に読んだページ数を下回っていたならば読み切れる
  return n < k ? 1 : 0 if m == 1

  # 前日にkページ読んているとき、m日で読める最大のページ数は、
  # (k - 1) + (k - 2) + ... + (k - m) = km - m(m + 1)/2 < n
  return @memo[[n, m, k]] = 0 if k * m < n + m * (m + 1) / 2

  ans = 0
  m_minus1 = m-1
  min = k-1 < n ? k-1 : n
  min.downto(1){|i|
    # solve2(100, 2, 101) = solve2(0, 1, )
    ans += solve2(n-i, m_minus1, i)
  }

  @memo[[n, m, k]] = ans
end

# nページの本をm日以内に読むパターンの総数を求める
def solve(n, m)
  ans = 0
  1.upto(m){|i| ans += solve2(n, i, n + 1) }
  ans
end

puts solve(180, 14)
puts "#{Time.now - s}s"