function solution(numbers) {
  var answer = '';
  answer = numbers.map(String).sort((a, b) => {
      return (b+a).localeCompare(a+b);
  }).join('');
  if (answer[0] == 0)
    return Number(answer).toString();
  return answer;
}

console.log(solution([6, 10, 2]))