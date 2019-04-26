s = gets.strip
$strs = ['dream', 'dreamer', 'erase', 'eraser'].freeze

def end_with_str(s)
  return nil if s == ""

  $strs.each do |str|
    return str if s.end_with?(str)
  end

  return nil
end

e = nil
while s != "" && e = end_with_str(s) do
  s = s.slice(0, s.length - e.length)
end

puts s == "" ? "YES" : "NO"
