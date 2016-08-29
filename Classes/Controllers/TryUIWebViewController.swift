//
//  TryUIWebViewController.swift
//  ATS-Check-iOS-Full_ATS
//
//  Created by ysmdsty on 2016/08/29.
//  Copyright © 2016年 ysmdsty. All rights reserved.
//

import UIKit

class TryUIWebViewController: UIViewController {

    @IBOutlet weak var webview: UIWebView!

    var urlString: String!

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
