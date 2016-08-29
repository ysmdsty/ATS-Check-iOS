//
//  WebViewListViewController.swift
//  ATS-Check-iOS-Full_ATS
//
//  Created by ysmdsty on 2016/08/29.
//  Copyright © 2016年 ysmdsty. All rights reserved.
//

import UIKit
import SegueContext

class WebViewListViewController: UITableViewController {
    enum RowDataType: String {
        case UIWebview = "UIWebview"
        case WKWebview = "WKWebview"
        case SafariView = "SafariView"
    }
    let dataSource: [RowDataType] = [
        .UIWebview,
        .WKWebview,
        .SafariView,
    ]

    var urlString: String!

    override func viewDidLoad() {
        super.viewDidLoad()

        guard let contextValue: String = contextValue() else {
            assertionFailure()
            return
        }
        urlString = contextValue
    }

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }

    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell: UITableViewCell! = tableView.dequeueReusableCellWithIdentifier("Cell", forIndexPath: indexPath)
        cell.textLabel?.text = dataSource[indexPath.row].rawValue
        return cell
    }

    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        tableView.deselectRowAtIndexPath(indexPath, animated: true)
        let data = dataSource[indexPath.row]
        switch data {
        case .UIWebview:
            self.performSegueWithIdentifier("Push_\(data.rawValue)", sender: nil, context: urlString, callback: nil)
        case .WKWebview:
            self.performSegueWithIdentifier("Push_\(data.rawValue)", sender: nil, context: urlString, callback: nil)
        case .SafariView:
            if #available(iOS 9.0, *) {
                let controller = TrySafariViewController(URL: NSURL(string: urlString)!, entersReaderIfAvailable: false)
                self.navigationController?.pushViewController(controller, animated: true)
            } else {
                // Fallback on earlier versions
            }
        }
    }

}
