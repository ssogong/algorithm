let cnt0 = 0;
let cnt1 = 0;
function search(a, b, len, arr) {
    let start = arr[a][b]; 
    for (let i = a; i < a+len; i++) {
        for (let j = b; j < b+len; j++) {
            if (arr[i][j] != start) {
                search(a, b, len/2, arr);
                search(a, b+len/2, len/2, arr);
                search(a+len/2, b, len/2, arr);
                search(a+len/2, b+len/2, len/2, arr);
                return;
            }
        }
    }
    if (start == 0)
        cnt0++;
    else
        cnt1++;
}

function solution(arr) {
    search(0, 0, arr.length, arr);
    return [cnt0, cnt1];
}
console.log(solution([[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]));