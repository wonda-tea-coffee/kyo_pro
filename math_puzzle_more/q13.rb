s = Time.now

def rotate(a)
  head = a[0]
  lim = head / 2 - 1
  0.upto(lim){|i|
    tmp = a[i]
    a[i] = a[head - i - 1]
    a[head - i - 1] = tmp
  }
  a
end

def len(a)
  ret = 0
  while a[0] != 1
    rotate(a)
    ret += 1
  end
  ret
end

N = 9
nums = (1..N).to_a

ans = 0
nums.permutation(N).each {|p|
  next if p[0] == 1
  next if p[p[0] - 1] == 1
  ans += 1 if len(Array.new(p)) == 5
}

puts ans
puts "#{Time.now - s}s"
