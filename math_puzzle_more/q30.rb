C, L = 32, 10
@memo = {}

def f(cnt_first, cnt_last, is_first)
  return @memo[[cnt_first, cnt_last, is_first]] if @memo[[cnt_first, cnt_last, is_first]]

  return cnt_first > cnt_last ? 1 : 0 if cnt_first + cnt_last == C && !is_first

  ans = 0
  1.upto(L){|i|
    break if cnt_first + cnt_last + i > C
    if is_first
      ans += f(cnt_first + i, cnt_last, false)
    else
      ans += f(cnt_first, cnt_last + i, true)
    end
  }

  @memo[[cnt_first, cnt_last, is_first]] = ans
end

puts f(0, 0, true)
