//
//  TryWKWebViewController.swift
//  ATS-Check-iOS-Full_ATS
//
//  Created by ysmdsty on 2016/08/29.
//  Copyright © 2016年 ysmdsty. All rights reserved.
//

import UIKit
import WebKit
import PureLayout

class TryWKWebViewController: UIViewController {
    weak var webview: WKWebView!

    var urlString: String!

    override func loadView() {
        super.loadView()
        let webview = WKWebView(forAutoLayout: ())
        view.addSubview(webview)
        webview.autoPinEdgesToSuperviewEdges()
        self.webview = webview
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        guard let contextValue: String = contextValue() else {
            assertionFailure()
            return
        }
        urlString = contextValue
        webview.loadRequest(NSURLRequest(URL: NSURL(string: urlString)!))
    }
}
