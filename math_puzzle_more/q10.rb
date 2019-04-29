$pref = [5381733, 1308265, 1279594, 2333899, 1023119, 1123891,
        1914039, 2916976, 1974255, 1973115, 7266534, 6222666,
        13515271, 9126214, 2304264, 1066328, 1154008, 786740,
        834930, 2098804, 2031903, 3700305, 7483128, 1815865,
        1412916, 2610353, 8839469, 5534800, 1364316, 963579,
        573441, 694352, 1921525, 2843990, 1404729, 755733,
        976263, 1385262, 728276, 5101556, 832832, 1377187,
        1786170, 1166338, 1104069, 1648177, 1433566];

$target = 289

def compare(d)
  sum = 0
  d = d.to_f
  $pref.each{|p|
    sum += (p / d).ceil
    return 1 if sum > $target
  }
  sum == $target ? 0 : -1
end

def out(d)
  d = d.to_f
  $pref.each {|p|
    puts "#{p}: #{(p / d).ceil}"
  }
end

min = 1
max = 1_000_000

while min < max
  mid = (max + min) / 2
  c = compare(mid)
  #puts "max = #{max}, mid = #{mid}, min = #{min}, c = #{c}"
  if c == 0
    puts mid
    out(mid)
    break
  elsif c == 1
    min = mid + 1
  else
    max = mid - 1
  end
end
