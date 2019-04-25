def cnt2(n)
  ret = 0
  while n % 2 == 0 do
    n /= 2
    ret += 1
  end
  ret
end

gets # N

puts gets.split.map{|n| cnt2(n.to_i)}.min
