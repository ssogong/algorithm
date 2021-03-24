function solution(board, moves) {
  var answer = 0;
  let new_board = [];
  let s = [];
  let len = board.length;
  for (let i = 1; i <= len; i++) {
      new_board[i] = [];
  }
  for (let i = len-1; i >= 0; i--) {
      for (let j = 0; j < len; j++) {
          if (board[i][j] > 0)
              new_board[j+1].push(board[i][j]);
      }
  }
  for (let move of moves) {
      if (new_board[move] === undefined || new_board[move].length == 0)
          continue;
      let friend = new_board[move].pop();
      if (s.length > 0 && s[s.length-1] == friend) {
          s.pop();
          answer += 2;
      } else {
          s.push(friend);
      }
  }
  return answer;
}

console.log(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]], [1,5,3,5,1,2,1,4]));
