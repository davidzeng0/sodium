const native = require('bindings')('nsodium') as NativeFunctions;

interface NativeFunctions{
	randombytes_buf(buf: Buffer | Uint8Array): number;
	crypto_secretbox_easy(out: Buffer | Uint8Array, inp: Buffer | Uint8Array, nonce: Buffer | Uint8Array, key: Buffer | Uint8Array): number;
}

export default native;