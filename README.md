
## Apple ATSについて
### リンク
* https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html

### 条件

* TLS 1.2
* 以下のうちの1つを利用
 * TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384
 * TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
 * TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384
 * TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
 * TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
 * TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
 * TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
 * TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
 * TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384
 * TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256
 * TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA
* forward securityが有効
* The leaf server certificate must be signed with one of the following types of keys
 * Rivest-Shamir-Adleman (RSA) key with a length of at least 2048 bits
 * Elliptic-Curve Cryptography (ECC) key with a size of at least 256 bits


### 確認方法１

* https://github.com/jvehent/cipherscan

#### 例

```
ciphersuite                  protocols  pfs                 curves
ECDHE-RSA-CHACHA20-POLY1305  TLSv1.2    ECDH,P-256,256bits  prime256v1
```

* ciphersuiteが指定のモノのうちの1つ
* protocolsがTLSv1.2
* pfsが"ECDH,P-256,256bits"でforward securityを満たす
* curvesがprime256v1でATS最後の条件を満たす(Elliptic-Curve Cryptography)

### 確認方法2
* サンプルプロジェクトで実際にリクエスト
