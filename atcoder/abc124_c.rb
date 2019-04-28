s = gets.chomp

start_time = Time.now

cnt = -1
while true
  cnt += 1

  i0 = s.index("00")
  unless i0.nil?
    s = s[0, i0] + s[i0 + 2, s.length]
    next
  end

  i1 = s.index("11")
  unless i1.nil?
    s = s[0, i1] + s[i1 + 2, s.length]
    next
  end
  

  break
end

puts cnt
