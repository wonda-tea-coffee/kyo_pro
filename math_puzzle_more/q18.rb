require './math'

def nxt(n)
  bin = rad(n, 10, 2)
  lim = bin.length - 1

  index = 1
  while index <= lim
    if bin[index-1] == '1' && bin[index] == '0'
      bin[index-1] = '0'
      bin[index] = '1'
      index += 2
      next
    end
    index += 1
  end

  bin[lim] = '0' if n % 2 == 1
  rad(bin, 2, 10).to_i
end

def cnt(n)
  return 0 if n == 0
  return @memo[n] if @memo[n]

  @memo[n] = 1 + cnt(nxt(n))
end

@memo = {}
ans = 0
1.upto(65535){|i| ans+=cnt(i)}

puts ans
