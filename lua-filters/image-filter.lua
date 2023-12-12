-- https://github.com/jgm/pandoc/issues/4894
function Image (img)
  if img.src:sub(1,1) == '/' then
    -- img.src = os.getenv 'WEBROOT' .. img.src
    img.src = '.' .. img.src
  end
  return img
end
