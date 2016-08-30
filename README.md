
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

### 確認方法 1

* nscurl  --ats-diagnostics http://example.com


### 確認方法 2

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

### 確認方法 3
* サンプルプロジェクトで実際にリクエスト


## 挙動詳細

### iOS8

* ATS未対応サイトもWebviewで読み込める
* ATS未対応サイトもNSURLSessionで読める

### iOS9/10

#### ATS完全有効化の場合

* iOS9 /iOS10

|種別|UIWebView | WkWebView | SFSafariViewController|
|-----|-----|-----|-----|
|ATS対応サイト|◯|◯|◯|
|ATS対応サイト<br />表示画像の取得先はATS未対応|☓<br />画像が?になる|☓<br />画像が?になる|◯|
|ATS未対応サイト|読み込めない|読み込めない|◯|

ATS対応サイトならNSURLSessionで読める

#### ATS一部有効化の場合 (Allow Arbitrary Loads in Web Content)

* iOS10

|種別|UIWebView | WkWebView | SFSafariViewController|
|-----|-----|-----|-----|
|ATS対応サイト|◯|◯|◯|
|ATS対応サイト<br />表示画像の取得先はATS未対応|◯|◯|◯|
|ATS未対応サイト|読み込めない|読み込めない|◯|

ATS対応サイトならNSURLSessionで読める

* iOS9

|種別|UIWebView | WkWebView | SFSafariViewController|
|-----|-----|-----|-----|
|ATS対応サイト|◯|◯|◯|
|ATS対応サイト<br />表示画像の取得先はATS未対応|☓<br />画像が?になる|☓<br />画像が?になる|◯|
|ATS未対応サイト|読み込めない|読み込めない|◯|

ATS対応サイトならNSURLSessionで読める

#### ATS無効化の場合 (Allow Arbitrary Loads)

* iOS10 / iOS9
 * ATS未対応サイトもWebviewで読み込める
 * ATS未対応サイトもNSURLSessionで読める

#### ATS一部有効化の場合 (Allow Arbitrary Loads in Web Content) & (Allow Arbitrary Loads)

* iOS10
 * Allow Arbitrary Loads in Web Contentのみの時と同じ
* iOS9
 * Allow Arbitrary Loadsのみの時と同じ

#### ATS一部有効化の場合 (下記のException Domainsを指定)

* Exception Domains
 * NSExceptionRequiresForwardSecrecy = NO
 * NSExceptionAllowsInsecureHTTPLoads = YES

 個々に(Allow Arbitrary Loads)を適用しているような扱いになる。
 ただし、読み込まれるページ内で読み込まれるリソースについては別途ドメインを指定(Exception Domains)していないと読み込まれない。
 画像なら?となる。


#### Webviewでのhttpアクセスの検出

proxyのログを見ると、ATSが有効の時httpリクエストは行われない。
ただし、httpリンクのクリックはUIWebview/WKWebviewともに検出出来る。


#### iOS9とiOS10の挙動の差異

proxyのログを見ると、Response結果に生かされているわけではないが、Htmlコンテンツ内のhttpリクエスト部分も一度、httpsでリクエストされているように見える。
