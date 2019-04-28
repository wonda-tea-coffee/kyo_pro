$cnts = {
  0 => 6,
  1 => 2,
  2 => 5,
  3 => 5,
  4 => 4,
  5 => 5,
  6 => 6,
  7 => 3,
  8 => 7,
  9 => 6,
}

def calc(n)
  $cnts[n / 10] + $cnts[n % 10]
end

ans = 0
0.upto(23) { |h|
  hcnt = calc(h)
  0.upto(59) { |m|
    mcnt = calc(m)
    0.upto(59) { |s|
      scnt = calc(s)
      ans += 1 if hcnt + mcnt + scnt == 30
    }
  }
}

puts ans
