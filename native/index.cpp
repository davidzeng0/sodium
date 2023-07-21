#include <napi.h>
#include <sodium/crypto_secretbox.h>
#include <sodium/randombytes.h>

Napi::Value n_randombytes_buf(const Napi::CallbackInfo& info){
	auto buf = info[0].As<Napi::Uint8Array>();

	randombytes_buf(buf.Data(), buf.ByteLength());

	return info.Env().Undefined();
}

Napi::Value n_crypto_secretbox_easy(const Napi::CallbackInfo& info){
	auto out = info[0].As<Napi::Uint8Array>();
	const auto in = info[1].As<Napi::Uint8Array>();
	const auto nonce = info[2].As<Napi::Uint8Array>();
	const auto key = info[3].As<Napi::Uint8Array>();

	crypto_secretbox_easy(out.Data(), in.Data(), in.ByteLength(), nonce.Data(), key.Data());

	return info.Env().Undefined();
}

Napi::Object init(Napi::Env env, Napi::Object exports){
	exports["randombytes_buf"] = Napi::Function::New(env, n_randombytes_buf);
	exports["crypto_secretbox_easy"] = Napi::Function::New(env, n_crypto_secretbox_easy);

	return exports;
}

NODE_API_MODULE(addon, init)