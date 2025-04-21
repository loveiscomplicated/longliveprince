let a = 10;

function change(x) {
  x = 20;
  return x;
}

console.log(change(a));
console.log(a); // 👉 10 (원본은 안 바뀜!)
