HOLL, SUM = 18, 72
@memo = {}

def solve(h, s)
  return s <= 5 ? 1 : 0 if h == 1
  return @memo[[h, s]] if @memo[[h, s]]

  ans = 0
  1.upto(5){|i|
    break if s == i
    ans += solve(h - 1, s - i)
  }
  @memo[[h, s]] = ans
end

puts solve(HOLL, SUM)
