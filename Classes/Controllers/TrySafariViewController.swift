//
//  TrySafariViewController.swift
//  ATS-Check-iOS-Full_ATS
//
//  Created by ysmdsty on 2016/08/29.
//  Copyright © 2016年 ysmdsty. All rights reserved.
//

import UIKit
import SafariServices

class TrySafariViewController: SFSafariViewController, SFSafariViewControllerDelegate {
    override func viewDidLoad() {
        super.viewDidLoad()
        self.delegate = self
    }
}
