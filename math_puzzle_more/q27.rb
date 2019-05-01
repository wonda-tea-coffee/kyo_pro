H, W, C = 20, 20, 10
@memo = {}

# 縦h、横wのチョコレートをc人で分ける
def solve(h, w, c)
  # 割るチョコが無い
  return 0 if h == 0 || w == 0
  # 1人ならそのまま食べればいいじゃない
  return 1 if c == 1
  return @memo[[h, w, c]] if @memo[[h, w, c]]

  ans = 0
  # 縦に割る
  1.upto(w-1){|i|
    # 1人にh * iのチョコをあげる
    ans += solve(h, w - i, c - 1)
  }
  # 横に割る
  1.upto(h-1){|i|
    # 1人にi * wのチョコをあげる
    ans += solve(h - i, w, c - 1)
  }
  @memo[[h, w, c]] = ans
end

puts solve(H, W, C) # 16
