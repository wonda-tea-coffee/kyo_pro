N = 11
PI = Math::PI.to_s.slice(0, N + 2).to_f

k = PI * 10**N
lk = PI
rk = (k + 1) / 10**N

a = 1
#puts "k = #{k}, lk = #{lk}, rk = #{rk}"

while true
  start_b = (lk * a).ceil
  end_b = (rk * a).floor
  #puts "a = #{a}: #{start_b} <= b <= #{end_b}"
  start_b.upto(end_b){|b|
    if (b/a.to_f).to_s.start_with?(PI.to_s)
      puts "π(#{N}) = #{a}, #{b}/#{a} = #{b/a.to_f}"
      exit
    end
  }
  a += 1
end
