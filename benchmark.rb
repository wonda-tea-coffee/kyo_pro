def test(title, &block)
  results = []
  cnt = 100000
  cnt.times {
    start_time = Time.now
    block.call
    results << Time.now - start_time
  }

  puts "#{title}: #{(results.inject(:+)) / cnt.to_f}s"
end
