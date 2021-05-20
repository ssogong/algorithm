function up_down(target) {
  let up = target.charCodeAt() - 'A'.charCodeAt();
  let down = 'Z'.charCodeAt() - target.charCodeAt() + 1;
  return Math.min(up, down);
}
function solution(name) {
  var answer = 0;
  let tmp = new Array(name.length).fill('A');
  let now = 0;
  while(1) {
      if (name[now] != tmp[now]) {
          answer += up_down(name[now]);
          tmp[now] = name[now];
      }
      if (tmp.join('') == name)
          break;
      // left
      let left = now;
      let left_cnt = 0;
      while(1) {
          left--;
          left_cnt++;
          if (left < 0)
              left = name.length - 1;
          if (name[left] != tmp[left])
              break;
      }
      // right
      let right = now;
      let right_cnt = 0;
      while(1) {
          right++;
          right_cnt++;
          if (right == name.length)
              right = 0;
          if (name[right] != tmp[right])
              break;
      }
      if (left_cnt < right_cnt) {
          now = left;
          answer += left_cnt;
      }
      else {
          now = right;
          answer += right_cnt;
      }
  }
  return answer;
}
console.log(solution("JEROEN"));