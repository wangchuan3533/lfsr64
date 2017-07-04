var lfsr64 = require('..');
var chars = 'abcdefghijklmnopqrstuvwxyz';
var buffer = Buffer.from([0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07]);
for (var i = 0; i < 10; i++) {
  console.log(buffer.toString('hex'));
  lfsr64.next(buffer);
}
