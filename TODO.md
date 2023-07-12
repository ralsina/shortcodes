# TODO and TODO'NT

## Things That May Get Done

* Produce decent error structures
* Inform tag type (% or <) in result
* Handle other kinds of quotes
* Handle escaping quote characters
* Handle escaping the shortcode itself like `\{{% foo %}}` (check with hugo docs)
* Report errors on mismatched `{{% foo >}}`
* Add self-closing shortcodes `{{< foo />}}` 
  (also, how TF do they work?)
* Add inline shortcodes `{{< time.inline >}}{{ now }}{{< /time.inline >}}`

* ~~Detect mismatched start/end like {{% foo >}}~~ 
