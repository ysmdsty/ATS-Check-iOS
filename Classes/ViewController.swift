//
//  ViewController.swift
//  ATS-Check-iOS-Full_ATS
//
//  Created by ysmdsty on 2016/08/21.
//  Copyright © 2016年 ysmdsty. All rights reserved.
//

import UIKit
import Bond
import SegueContext

class ViewController: UIViewController {

    @IBOutlet weak var pickerView: UIPickerView!
    @IBOutlet weak var segmented: UISegmentedControl!
    @IBOutlet weak var requestButton: UIButton!
    @IBOutlet weak var webviewButton: UIButton!
    @IBOutlet weak var indicatorView: UIActivityIndicatorView!
    @IBOutlet weak var textView: UITextView!
    @IBOutlet weak var resultLabel: UILabel!

    var dataSource: [String] = Constants.url
    let loadingState = Observable<LoadingState>(.None)

    let resultText = Observable<String>("")
    let resultLabelText = Observable<String>("")

    enum LoadingState {
        case None
        case Loading
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        pickerView.delegate = self
        pickerView.dataSource = self

        loadingState.map {$0 != LoadingState.Loading }.deliverOn(.Main).bindTo(indicatorView.bnd_hidden)
        loadingState.map {$0 == LoadingState.Loading }.deliverOn(.Main).bindTo(indicatorView.bnd_animating)
        loadingState.map {$0 != LoadingState.Loading }.deliverOn(.Main).bindTo(requestButton.bnd_enabled)
        requestButton.bnd_tap.throttle(0.1, queue: .Main).observeNew { [weak self] in
            self?.loadingState.value = .Loading
            self?.clear()
            self?.request()
        }
        resultText.deliverOn(.Main).bindTo(textView.bnd_text)
        resultLabelText.deliverOn(.Main).bindTo(resultLabel.bnd_text)

        webviewButton.bnd_tap.throttle(0.1, queue: .Main).observeNew { [unowned self] in
            let urlString: String = self.dataSource[self.pickerView.selectedRowInComponent(0)]

            let identifier = "WebViewListViewController"
            self.pushViewControllerWithStoryboardName(identifier, identifier: identifier,
                bundle: nil, animated: true, context: urlString, callback: nil)
        }
    }

    func clear() {
        resultText.value = ""
        resultLabelText.value = ""
    }

    func request() {
        let method: String! = segmented.titleForSegmentAtIndex(segmented.selectedSegmentIndex)
        let urlString = dataSource[pickerView.selectedRowInComponent(0)]
        let url: NSURL! = NSURL(string: urlString)
        let request = NSMutableURLRequest(URL: url)
        request.HTTPMethod = method

        NSURLSession.sharedSession()
            .dataTaskWithRequest(request) {
                [weak self] (data: NSData?, response: NSURLResponse?, error: NSError?) in

                if let error = error {
                    self?.resultLabelText.value = "ERROR"
                    self?.resultText.value = error.description
                } else {
                    self?.resultLabelText.value = "SUCCESS"
                    self?.resultText.value = String(data: data ?? NSData(), encoding: NSUTF8StringEncoding) ?? ""
                }
                self?.loadingState.value = .None
        }.resume()
    }
}

extension ViewController: UIPickerViewDelegate {
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return dataSource[row]
    }
}

extension ViewController: UIPickerViewDataSource {
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return 1
    }
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return dataSource.count
    }
}
